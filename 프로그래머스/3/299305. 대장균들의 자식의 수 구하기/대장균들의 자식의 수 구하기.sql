WITH A(P_ID, CHILD_COUNT) AS(
SELECT PARENT_ID, COUNT(ID)
FROM ECOLI_DATA
WHERE PARENT_ID IS NOT NULL
GROUP BY PARENT_ID)

SELECT ID, IFNULL(CHILD_COUNT, 0) AS CHILD_COUNT
FROM ECOLI_DATA E LEFT JOIN A AA ON E.ID = AA.P_ID
ORDER BY ID;