DELETE e1
FROM Person e1
INNER JOIN Person e2
ON e1.email = e2.email
AND e1.id > e2.id;