SELECT B.ANIMAL_ID AS ANIMAL_ID, B.NAME AS NAME
FROM ANIMAL_INS A RIGHT OUTER JOIN ANIMAL_OUTS B ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE B.ANIMAL_ID NOT IN (SELECT B.ANIMAL_ID
                         FROM ANIMAL_INS A INNER JOIN ANIMAL_OUTS B ON A.ANIMAL_ID = B.ANIMAL_ID)
ORDER BY ANIMAL_ID ASC;