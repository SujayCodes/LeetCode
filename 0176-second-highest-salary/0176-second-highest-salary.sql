# Write your MySQL query statement below

# Approach :: MAKE A NEW TABLE WITH EXCLUDING THE MAX SLARY ROW AND THEN FIND THE MAX SALARY AMONG THE REST TABLE


SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE 
(salary<(SELECT MAX(salary) from Employee))
;