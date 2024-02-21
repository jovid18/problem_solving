function solution(number) {
  // 삼총사
  // number 배열 중에서 3개 숫자를 더해서 0이 되는 경우의수
  //
  let answer = 0;

  //
  for (let i = 0; i < number.length; i++) {
    for (let j = i + 1; j < number.length; j++) {
      for (let k = j + 1; k < number.length; k++) {
        if (number[i] + number[j] + number[k] === 0) {
          answer++;
        }
      }
    }
  }
  return answer;
}
let number = [1, 2, 3, 4, 5];
solution(number);
