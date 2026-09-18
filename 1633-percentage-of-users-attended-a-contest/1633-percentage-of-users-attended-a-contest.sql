SELECT e2.contest_id, ROUND(COUNT(e2.user_id) * 100.0 /(SELECT COUNT(*) FROM Users),2) AS percentage
FROM Users e1
INNER JOIN Register e2
ON e1.user_id = e2.user_id
GROUP BY e2.contest_id
ORDER BY percentage DESC, e2.contest_id ASC;