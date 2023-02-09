SELECT f.FLAVOR AS FLAVOR
FROM FIRST_HALF AS f INNER JOIN ICECREAM_INFO AS i ON f.FLAVOR = i.FLAVOR
WHERE f.TOTAL_ORDER > 3000 AND i.INGREDIENT_TYPE = 'fruit_based'
ORDER BY f.TOTAL_ORDER DESC;