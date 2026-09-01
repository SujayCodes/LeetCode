# Write your MySQL query statement below

SELECT e1.id
FROM Weather e1
LEFT JOIN 
Weather e2 
ON e1.recordDate = DATE_ADD(e2.recordDate, INTERVAL 1 DAY)      -- e1's date must be exactly 1 day after e2's date.
WHERE e1.temperature > e2.temperature 
;


-- After self-join:

-- e1 (today)              e2 (yesterday)

-- id  date     temp       id  date     temp
-- 1   Jan 1    10         NULL
-- 2   Jan 2    25         1   Jan 1    10
-- 3   Jan 3    20         2   Jan 2    25
-- 4   Jan 4    30         3   Jan 3    20