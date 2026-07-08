# Write your MySQL query statement below
WITH reading_list AS (
    SELECT 
        book_id,
        MIN(session_rating) AS min_rating,
        MAX(session_rating) AS max_rating,
        COUNT(CASE 
                WHEN session_rating <= 2 OR session_rating >= 4 
                THEN 1 
              END) AS ext_nrating,
        COUNT(*) AS total_sessions
    FROM reading_sessions
    GROUP BY book_id
    HAVING COUNT(*) >= 5
       AND MIN(session_rating) <= 2
       AND MAX(session_rating) >= 4
)

SELECT 
    r.book_id,
    b.title,
    b.author,
    b.genre,
    b.pages,
    (r.max_rating - r.min_rating) AS rating_spread,
    ROUND(r.ext_nrating / r.total_sessions, 2) AS polarization_score
FROM books b
JOIN reading_list r 
    ON b.book_id = r.book_id
WHERE (r.ext_nrating / r.total_sessions) >= 0.6
ORDER BY polarization_score desc,b.title desc ;