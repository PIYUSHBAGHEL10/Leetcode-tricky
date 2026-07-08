/* Write your SQL query statement below */
WITH per_week AS(
SELECT
	employee_id,SUM(duration_hours) TotalHours
FROM 
	meetings
GROUP BY 
    employee_id,
    WEEKOFYEAR(meeting_date), YEAR(meeting_date)
)
SELECT
	PW.employee_id,EE.employee_name,EE.department, COUNT(PW.employee_id) meeting_heavy_weeks 
FROM 
	per_week PW
	INNER JOIN 
	employees EE ON PW.employee_id = EE.employee_id
WHERE 
	PW.TotalHours > 20
GROUP BY PW.employee_id,EE.employee_name,EE.department
HAVING COUNT(PW.employee_id) > 1
ORDER BY meeting_heavy_weeks DESC, EE.employee_name