from sklearn.ensemble import RandomForestRegressor
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
import numpy as np

class 过滤阻力:
    def __init__(self,X,y) -> None:
        X=self.__expand(X)
        self.instance=LinearRegression(n_jobs=-1).fit(X,y)
    def __call__(self, x):
        x=self.__expand(x)
        return self.instance.predict(x)
    def __expand(self,X):
        X=PolynomialFeatures(degree=3).fit_transform(X)
        return X