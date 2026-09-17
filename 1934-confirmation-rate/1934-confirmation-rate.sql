# Write your MySQL query statement below


SELECT 
    e1.user_id,
    ROUND(IFNULL(AVG(e2.action = 'confirmed'), 0), 2) AS confirmation_rate
FROM Signups e1
LEFT JOIN Confirmations e2
ON e1.user_id = e2.user_id
GROUP BY e1.user_id;