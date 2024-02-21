function tentothree(n) {
  let arr = []; //나머지를 담을 배열을 선언
  while (n !== 0) {
    let remain = n % 3; // 나머지
    arr.push(remain); // arr에 나머지를 저장
    let share = Math.floor(n / 3); //몫
    n = share;
  }
  return arr;
}

function threetoten(n) {
  let ret = 0;
  let cnt = 0;
  while (n !== 0) {
    let remain = n % 10;
    ret += remain * Math.pow(3, cnt);
    n = Math.floor(n / 10);
    cnt++;
  }
  return ret;
}
function solution(n) {
  let num3 = tentothree(n);
  let answer = threetoten(Number(num3.join('')));
  return answer;
}
console.log(tentothree(100000000));
console.log(10221021111022202);
console.log(solution(100000000));
