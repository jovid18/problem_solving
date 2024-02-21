// 변환 예시: 10진법의 수를 3진법으로 변환하려면, 주어진 수를 3으로 나누고, 나머지를 기록하는 과정을 반복합니다. 이 과정을 수가 0이 될 때까지 계속하고,
// 마지막에 얻은 나머지를 역순으로 읽으면 그것이 3진법으로의 표현입니다.

//10진법을 3진법으로 바꾸는 함수

// 주어진 10진법 수를 3으로 나눕니다.
// 나머지를 기록합니다.
// 나눗셈의 몫을 다시 3으로 나눕니다.
// 마찬가지로 나머지를 기록
// 이 과정을 몫이 0이 될 때까지 반복합니다.
// 41을 직접 손으로 3진법
// 41 % 3 = 13...2
// 13 % 3 = 4...1
// 4 % 3 = 1...1
// 1 % 3 = 0 ...1
//나머지를 역으로  1112
function tentothree(n) {
  let arr = []; //나머지를 담을 배열을 선언
  while (n !== 0) {
    //n :28
    //remain: 1
    //share :9
    //n:9
    let remain = n % 3; // 나머지
    arr.push(remain); // arr에 나머지를 저장
    let share = Math.floor(n / 3); //몫
    n = share;
  }
  arr.reverse();
  return Number(arr.join(''));
}

//3진법을 10진법으로 바꾸는 함수
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
  // 3진법 뒤집기
  //n이 10진법 숫자
  // 1번째 할일: 3진법으로 바꾸는 것
  // 2번째 할일: 1의 결과를 뒤집기
  // 3번재 할이리 10진법으로 바꾸기
  let num3 = tentothree(n);
  console.log(num3);
  let reversenum3 = Number([...String(num3)].reverse().join(''));
  let answer = threetoten(reversenum3);

  return answer;
}
let num = 20222011112012201;
console.log(2 ** 51);
console.log(num);

//스트케이스10은 [입력값:78413450 , 기댓값:110105530] 입니다
