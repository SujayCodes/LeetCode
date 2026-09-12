SELECT e1.customer_id, COUNT(*) AS count_no_trans
FROM Visits e1
LEFT JOIN Transactions e2
    ON e1.visit_id = e2.visit_id
WHERE e2.transaction_id IS NULL
GROUP BY e1.customer_id;