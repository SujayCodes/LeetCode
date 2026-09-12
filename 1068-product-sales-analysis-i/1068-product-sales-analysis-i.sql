SELECT e2.product_name, e1.year, e1.price
FROM Sales e1
INNER JOIN Product e2
ON e1.product_id = e2.product_id
;