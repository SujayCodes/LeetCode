# Write your MySQL query statement below


SELECT e1.product_id, ROUND(IFNULL(SUM(e1.price * e2.units) / SUM(e2.units),0), 2) AS average_price
FROM Prices e1
LEFT JOIN 
UnitsSold e2
ON e1.product_id = e2.product_id
AND e2.purchase_date BETWEEN e1.start_date AND e1.end_date
GROUP BY e1.product_id;