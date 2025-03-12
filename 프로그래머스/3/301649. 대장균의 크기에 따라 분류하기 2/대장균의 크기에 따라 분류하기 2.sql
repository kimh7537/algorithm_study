SELECT ID,
    CASE 
        WHEN SizeRank = 1 THEN 'CRITICAL'
        WHEN SizeRank = 2 THEN 'HIGH'
        WHEN SizeRank = 3 THEN 'MEDIUM'
        WHEN SizeRank = 4 THEN 'LOW'
    END AS COLONY_NAME
FROM 
    (
    SELECT 
        ID,
        SIZE_OF_COLONY,
        NTILE(4) OVER (ORDER BY SIZE_OF_COLONY DESC) AS SizeRank
    FROM 
        ECOLI_DATA
) as RankedColony
ORDER BY ID;