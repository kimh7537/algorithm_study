# SELECT SUM(SCORE) AS SCORE, E.EMP_NO as EMP_NO, EMP_NAME, POSITION, EMAIL
# FROM HR_EMPLOYEES E JOIN HR_GRADE G ON E.EMP_NO = G.EMP_NO
# GROUP BY E.EMP_NO, EMP_NAME, POSITION, EMAIL
# HAVING SUM(SCORE) = (SELECT MAX(TOTAL)
#                       FROM (SELECT SUM(SCORE) AS TOTAL
#                            FROM HR_EMPLOYEES A JOIN HR_GRADE B ON A.EMP_NO = B.EMP_NO
#                            GROUP BY A.EMP_NO) as Q
#                       );

SELECT SUM(SCORE) AS SCORE, E.EMP_NO as EMP_NO, EMP_NAME, POSITION, EMAIL
FROM HR_EMPLOYEES E JOIN HR_GRADE G ON E.EMP_NO = G.EMP_NO
GROUP BY E.EMP_NO, EMP_NAME, POSITION, EMAIL
HAVING SUM(SCORE) >= all (SELECT SUM(SCORE)
                           FROM HR_EMPLOYEES A JOIN HR_GRADE B ON A.EMP_NO = B.EMP_NO
                           GROUP BY A.EMP_NO, EMP_NAME, POSITION, EMAIL);