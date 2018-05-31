'''
    This is generalized dice loss for organs, which means you can compute dice for more than one organ at a time
input:
    inputs: predicted segmentation map, tensor type, even Variable
    targets: real segmentation map, tensor type, even Variable
    
output:
    loss: scalar
    
    Sep, 2017, let's test, succeed
'''
   
class GeneralizedDiceLoss4Organs(nn.Module):
    def __init__(self,  organIDs = [1], size_average=True):   
        super(GeneralizedDiceLoss4Organs,self).__init__()
        self.organIDs = organIDs
        self.size_average = size_average
        
    def forward(self, inputs, targets, save=True):
        """
            Args:
                inputs:(n, c, h, w, d)
                targets:(n, h, w, d): 0,1,...,C-1       
        """
        assert not targets.requires_grad
        assert inputs.dim() == 5, inputs.shape
        assert targets.dim() == 4, targets.shape
        assert inputs.size(0) == targets.size(0), "{0} vs {1} ".format(inputs.size(0), targets.size(0))
        assert inputs.size(2) == targets.size(1), "{0} vs {1} ".format(inputs.size(2), targets.size(1))
        assert inputs.size(3) == targets.size(2), "{0} vs {1} ".format(inputs.size(3), targets.size(2))
        assert inputs.size(4) == targets.size(3), "{0} vs {1} ".format(inputs.size(4), targets.size(3))
        
        
        eps = Variable(torch.cuda.FloatTensor(1).fill_(0.000001))
        one = Variable(torch.cuda.FloatTensor(1).fill_(1.0))
        two = Variable(torch.cuda.FloatTensor(1).fill_(2.0))
                          
        inputSZ = inputs.size() #it should be sth like NxCxHxW
        
        inputs = F.softmax(inputs, dim=1)
    
        numOfCategories = inputSZ[1]
        assert numOfCategories==len(self.organIDs), 'organ weights is not matched with organs (bg should be included)'
        ####### Convert categorical to one-hot format

        results_one_hot = inputs
        
        
        target1 = Variable(torch.unsqueeze(targets.data,1)) #Nx1xHxW
        targets_one_hot = Variable(torch.cuda.FloatTensor(inputSZ).zero_()) #NxCxHxW
        targets_one_hot.scatter_(1, target1, 1) #scatter along the 'numOfDims' dimension
 
        ###### Now the prediction and target has become one-hot format
        ###### Compute the dice for each organ
        out = Variable(torch.cuda.FloatTensor(1).zero_(), requires_grad = True)
    #     intersect = Variable(torch.cuda.FloatTensor([1]).zero_(), requires_grad = True)
    #     union = Variable(torch.cuda.FloatTensor([1]).zero_(), requires_grad = True)

        intersect = Variable(torch.cuda.FloatTensor(1).fill_(0.0))
        union = Variable(torch.cuda.FloatTensor(1).fill_(0.0))
        
        for organID in range(0, numOfCategories):

            target = targets_one_hot[:,organID,...].contiguous().view(-1,1).squeeze(1) #for 2D or 3D
            result = results_one_hot[:,organID,...].contiguous().view(-1,1).squeeze(1) #for 2D or 3D
    #             print 'unique(target): ',unique(target),' unique(result): ',unique(result)
#             if torch.sum(target)==0:
#                 organWeight =0
#             else:
            organWeight = 1/((torch.sum(target))**2+eps)
#             print 'sum: %d'%torch.sum(target),' organWeight: %f'%organWeight
    #         intersect = torch.dot(result, target)
            intersect_vec = result * target
            intersect = intersect + organWeight*torch.sum(intersect_vec)
    #         print type(intersect)
            # binary values so sum the same as sum of squares
            result_sum = torch.sum(result)
    #         print type(result_sum)
            target_sum = torch.sum(target)
            union = union + organWeight*(result_sum + target_sum) + (two*eps)
    
            # the target volume can be empty - so we still want to
            # end up with a score of 1 if the result is 0/0
            
        IoU = intersect / union
#             out = torch.add(out, IoU.data*2)
        out =  one - two*IoU

    #     print type(out)
        return out      
