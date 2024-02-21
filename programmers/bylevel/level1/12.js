function solution(a, b) {
  //최소값 :
  //각 정수 합 구하기 -> return
  //a가 b보다 큰 경우 swap
  if (a > b) [a, b] = [b, a];
  var answer = 0;
  if (a === b) {
    return a;
  } else {
    for (let i = a; i <= b; i++) {
      answer += i;
    }
  }
  return answer;
}
