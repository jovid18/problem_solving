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

  for (let i = left; i <= right; i++) {
    answer +=Number.isInteger(Math.sqrt(i))? -i:i;

  }

  return answer;
}
