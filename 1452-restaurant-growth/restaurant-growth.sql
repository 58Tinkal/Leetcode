SELECT 
    c.visited_on,
    (SELECT SUM(amount) 
     FROM Customer 
     WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
    ) AS amount,
    (
        SELECT ROUND(SUM(amount) / 7, 2) 
        FROM Customer 
        WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
    ) AS average_amount
FROM Customer AS c
WHERE c.visited_on >= (
    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY) FROM Customer
)
GROUP BY c.visited_on;
