SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS
WHERE (SKILL_CODE & (1 << 8)) = 256 OR (SKILL_CODE & (1 << 10)) = 1024
ORDER BY ID ASC;

# 100000000 256
# 10000000000 1024