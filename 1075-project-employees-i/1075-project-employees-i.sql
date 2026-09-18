# Write your MySQL query statement below

SELECT e1.project_id, ROUND(AVG(e2.experience_years),2) AS average_years
FROM Project e1
INNER JOIN 
Employee e2
ON e1.employee_id = e2.employee_id
GROUP BY e1.project_id
;