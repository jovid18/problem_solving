function solution(food) {
  var answer = "0";
  food.reverse();
  food.forEach((quantity, index) => {
    if (quantity % 2 === 1) quantity--;
    quantity /= 2;
    index = food.length - index - 1;
    for (let i = 0; i < quantity; ++i) {
      answer = index + answer + index;
    }
  });
  return answer;
}