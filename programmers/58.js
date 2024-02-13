function solution(ingredient) {
  let answer = 0;
  let arr = [];
  for (let i = 0; i < ingredient.length; ++i) {
    arr.push(ingredient[i]);
    if (arr.length >= 4) {
      let j = arr.length - 1;
      if (arr[j - 3] === 1 && arr[j - 2] === 2 && arr[j - 1] === 3 && arr[j] === 1) {
        answer++;
        arr.pop();
        arr.pop();
        arr.pop();
        arr.pop();
      }
    }
  }

  return answer;
}
ingredient = [2, 1, 1, 2, 3, 1, 2, 3, 1];
console.log(solution(ingredient));
