SELECT COUNT(*) AS USERS
FROM USER_INFO
WHERE 20 <= AGE AND AGE <= 29 AND YEAR(JOINED) = 2021;