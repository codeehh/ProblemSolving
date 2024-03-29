SELECT PRODUCT_CODE, (PRICE * SUM) AS SALES
FROM PRODUCT AS a INNER JOIN (SELECT PRODUCT_ID, sum(SALES_AMOUNT) AS SUM FROM OFFLINE_SALE GROUP BY PRODUCT_ID) AS b
ON a.PRODUCT_ID = b.PRODUCT_ID
ORDER BY SALES DESC, PRODUCT_CODE ASC;