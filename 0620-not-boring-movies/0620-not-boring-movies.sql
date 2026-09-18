# USING CTE



WITH CTE AS
(
    SELECT *
    FROM Cinema
    WHERE id % 2 = 1
      AND description <> 'boring'
)
SELECT *
FROM CTE
ORDER BY rating DESC;