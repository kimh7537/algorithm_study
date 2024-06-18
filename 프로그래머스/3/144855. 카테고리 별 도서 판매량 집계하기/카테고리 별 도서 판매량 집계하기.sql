SELECT CATEGORY, SUM(SALES) as TOTALSALES
FROM BOOK join BOOK_SALES using(BOOK_ID)
WHERE SALES_DATE like "2022-01%"
GROUP BY CATEGORY
ORDER BY CATEGORY;