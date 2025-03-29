SELECT HISTORY_ID,
    CASE 
		    WHEN DP.DURATION_TYPE IS NULL THEN ROUND(DD.DAILY_FEE * DD.DAY, -1)
		    ELSE ROUND((DD.DAILY_FEE * ((100 - DP.discount_rate) / 100)) *DD.DAY , -1)
    END AS FEE
FROM (SELECT RH.HISTORY_ID, CC.CAR_ID, CC.CAR_TYPE, CC.DAILY_FEE, 
        DATEDIFF(end_date, start_date) + 1 AS DAY,
        CASE 
		        WHEN DATEDIFF(end_date, start_date) + 1 >= 90 THEN '90일 이상'
		        WHEN DATEDIFF(end_date, start_date) + 1 >= 30 THEN '30일 이상'
		        WHEN DATEDIFF(end_date, start_date) + 1 >= 7 THEN '7일 이상'
        END AS DURATION_TYPE
      FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY AS RH LEFT JOIN CAR_RENTAL_COMPANY_CAR AS CC ON RH.CAR_ID = CC.CAR_ID
      WHERE CC.CAR_TYPE = '트럭') AS DD
LEFT JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS DP ON DD.CAR_TYPE = DP.CAR_TYPE AND DD.DURATION_TYPE = DP.DURATION_TYPE
ORDER BY FEE DESC, HISTORY_ID DESC;