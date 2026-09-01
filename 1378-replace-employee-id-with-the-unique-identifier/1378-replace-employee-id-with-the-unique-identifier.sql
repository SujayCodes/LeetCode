# Write your MySQL query statement below

-- SELECT e1.unique_id , e2.name 
-- FROM EmployeeUNI e1
-- RIGHT JOIN
-- Employees e2
-- ON e1.id = e2.id
-- ;




SELECT e1.name, e2.unique_id
FROM Employees e1
LEFT JOIN
EmployeeUNI e2
ON e1.id = e2.id
;