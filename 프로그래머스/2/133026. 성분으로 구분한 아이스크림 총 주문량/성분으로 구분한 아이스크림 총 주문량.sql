SELECT INGREDIENT_TYPE, sum(TOTAL_ORDER) as TOTAL_ORDER from FIRST_HALF f
 inner join icecream_info i
 on f.flavor = i.flavor
 group by i.ingredient_type
 order by TOTAL_ORDER