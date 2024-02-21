//약수의 개수를 구하는 함수
function finddivisor(n) {
  var answer = 0;
  for (let i = 1; i * i <= n; ++i) {
    if (i * i === n) answer++;
    else if (n % i == 0) answer += 2;
  }
  return answer;
}

function solution(left, right) {
  let answer = 0;
  //풀이 1
  // 약수의 개수를 구하는 함수를 만들고
  // left부터 right까지 for문 돌리고
  // 약수의 개수가 짝수일 때는 더하고 홀수 일 때는 빼는

  //풀이 2
  //약수의 개수가 홀수인지 짝수인지만 알면되는데
  //약수의 개수가 홀수인 애-> 제곱수 (1,4,9,16,25)
  // 20 => (1,20) (2,10) (4,5) => 6개
  // 18 => (1,18) (2,9) (3,6) => 6개

  // 16 => (1,16) (2,8) (4) => 5개
  // 25 => (1,25) (5) => 3개
  //Number.isInteger(Math.sqrt(i)) => i가 제곱수인지 판별
  for (let i = left; i <= right; i++) {
    answer +=Number.isInteger(Math.sqrt(i))? -i:i;
    // if (!Number.isInteger(Math.sqrt(i))) {
    //   answer += i;
    // } else {
    //   answer -= i;
    // }
  }

  return answer;
}
//소인수 분해하는 코드도 존재 
