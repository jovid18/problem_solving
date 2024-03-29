SELECT FP.CATEGORY, MP.MAX_PRICE, FP.PRODUCT_NAME
FROM FOOD_PRODUCT FP
INNER JOIN (
    SELECT CATEGORY, MAX(PRICE) AS MAX_PRICE
    FROM FOOD_PRODUCT
    GROUP BY CATEGORY
) MP ON FP.CATEGORY = MP.CATEGORY AND FP.PRICE = MP.MAX_PRICE
WHERE FP.CATEGORY in ("과자","국","김치","식용유")
ORDER BY MP.MAX_PRICE DESC;
