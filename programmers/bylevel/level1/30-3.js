// 10진수를 3진법 문자열로 변환하는 함수
function tentothree(decimalNumber) {
  let ternaryString = ''; // 변환된 3진법을 저장할 문자열
  while (decimalNumber !== 0) {
    let remainder = decimalNumber % 3; // 현재 숫자를 3으로 나눈 나머지
    ternaryString = String(remainder) + ternaryString; // 나머지를 문자열의 앞에 추가
    let quotient = Math.floor(decimalNumber / 3); // 현재 숫자를 3으로 나눈 몫
    decimalNumber = quotient; // 몫을 다음 반복의 숫자로 설정
  }
  return ternaryString;
}

// 3진법 문자열을 10진수로 변환하는 함수
function threetoten(ternaryString) {
  let decimalResult = 0n; // 최종 10진수 결과를 저장할 BigInt 변수
  for (let i = 0; i < ternaryString.length; ++i) {
    decimalResult += BigInt(Number(ternaryString[i])) * 3n ** BigInt(ternaryString.length - i - 1);
  }
  return decimalResult;
}

// 주어진 10진수를 3진법으로 변환, 뒤집은 후, 다시 10진수로 변환하는 함수
function solution(n) {
  let ternaryRepresentation = tentothree(n); // 10진수를 3진법 문자열로 변환
  let reversedTernary = [...ternaryRepresentation].reverse().join(''); // 변환된 3진법 문자열을 뒤집음
  let finalDecimal = threetoten(reversedTernary); // 뒤집힌 3진법 문자열을 다시 10진수로 변환
  return finalDecimal;
}
