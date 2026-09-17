# https://chatgpt.com/share/6aaba11e-c02c-83e8-9402-d1192a8d6299

SELECT e1.name
FROM Employee e1
JOIN Employee e2
ON e1.id = e2.managerId
GROUP BY e2.managerId
HAVING COUNT(e2.managerId)>=5
;