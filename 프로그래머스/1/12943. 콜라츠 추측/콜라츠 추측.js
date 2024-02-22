function solution(num) {
  //콜라츠 추측
  let cnt = 0;
  while (num !== 1) {
    if (num % 2 === 1) {
      num = 3 * num + 1;
    } else {
      num /= 2;
    }
    cnt++;
  }
  if (cnt >= 500) {
    cnt = -1;
  }
  return cnt;
}