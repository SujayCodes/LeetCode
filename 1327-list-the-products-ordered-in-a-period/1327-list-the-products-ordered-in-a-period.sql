SELECT e1.product_name,SUM(e2.unit) AS unit
FROM Products e1
INNER JOIN Orders e2
ON e1.product_id = e2.product_id
WHERE order_date >= '2020-02-01' AND order_date < '2020-03-01'
GROUP BY e1.product_name
HAVING SUM(e2.unit) >= 100;