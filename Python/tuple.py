#order, unchanged, and allow duplicate

z=('car','bike',30,40,3.14,True,'bike')

y=list(z)
y[1]='oranges'
x=tuple(y)

print(x)