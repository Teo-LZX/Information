from sklearn.ensemble import RandomForestRegressor
import numpy as np

class regressor:
    def __init__(self,X,y) -> None:
        X=self.__expand(X)
        self.instance=RandomForestRegressor(max_depth=8,max_leaf_nodes=24,criterion='absolute_error').fit(X,y)
    def __call__(self, x):
        x=self.__expand(x)
        return self.instance.predict(x)
    def __expand(self,X):
        trainData=[X]
        trainData.append(X**2)
        trainData.append(X**3)
        trainData.append(X**4)
        trainData.append(X[:,[0]]+X[:,[1]])
        trainData.append(X[:,[0]]-X[:,[1]])
        trainData.append(X[:,[0]]*X[:,[1]])
        X=np.concatenate(trainData,axis=1)
        return X