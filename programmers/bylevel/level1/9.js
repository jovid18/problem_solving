function solution(n) {
  //n이 양의 정수 x의 제곱이라면 x+1의 제곱을 리턴하고,
  //n이 양의 정수 x의 제곱이 아니라면 -1을 리턴하는 함수
  let x = Math.sqrt(n);
  if (Number.isInteger(x)) {
    return Math.pow(x + 1, 2);
  } else {
    return -1;
  }
}

//pow(a,b) a의 b제곱
//n **0.5 
