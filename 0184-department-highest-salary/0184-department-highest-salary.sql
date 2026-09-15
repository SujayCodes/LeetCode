# Write your MySQL query statement below

SELECT e2.name AS Department, e1.name AS Employee, e1.salary AS Salary
FROM Employee e1
INNER JOIN 
Department e2
ON e1.departmentId = e2.id
WHERE (e1.departmentId, e1.salary) IN
(SELECT departmentId, MAX(salary)
FROM Employee 
GROUP BY departmentId
)
;
