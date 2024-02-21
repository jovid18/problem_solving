function solution(x, n) {
  //함수 solution은 정수 x와 자연수 n을 입력 받아,
  //x부터 시작해 x씩 증가하는 숫자를 n개 지니는 리스트를 리턴.answer
  var answer = [];
  for (let i = 1; i <= n; ++i) {
    answer.push(x * i);
  }
  return answer;
}
