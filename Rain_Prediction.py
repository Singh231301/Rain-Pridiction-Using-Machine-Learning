import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error,r2_score

data = pd.read_csv(r"C:\Users\yasha\Desktop\improved_dataset.csv")
data = data.drop(['Description'], axis = 1)

#Attributes
x = data.iloc[:,:-1]
#Target
y = data.iloc[:,-1]
x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.3,random_state=0)
print(x)
print(y)

regressor = LinearRegression()
regressor.fit(x,y)

#Coefficients ans Intercepts
print(regressor.coef_)
print(regressor.intercept_)

#Predictions
y_pred = regressor.predict(x_test)
print(y_test)
print(y_pred)

#Scatter Plot
plt.scatter(y_test,y_pred) 
plt.xlabel("Actual value")
plt.ylabel("Predicted value")
plt.show()

from sklearn.metrics import r2_score 
r2_score(y_test,y_pred)
mean_squared_error(y_test,y_pred)