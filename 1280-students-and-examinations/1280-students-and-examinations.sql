# Write your MySQL query statement below

SELECT e1.student_id,
       e1.student_name,
       e2.subject_name,
       COUNT(e3.student_id) AS attended_exams
FROM Students e1
CROSS JOIN Subjects e2
LEFT JOIN Examinations e3
ON e1.student_id = e3.student_id
AND e2.subject_name = e3.subject_name
GROUP BY e1.student_id,
         e1.student_name,
         e2.subject_name
ORDER BY e1.student_id,
         e2.subject_name
;