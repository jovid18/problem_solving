function solution(price, money, count) {
  // price: 놀이기구 처음 이용료
  // money: 현재 가지고 있는 money
  // count: 놀이기구를 탈 횟수

  //부족한 금액 계산하기
  // 1번 탔을 때 총 비용: price
  // 2번 탔을 때 총 비용: price + 2*price
  // 3번 탔을 때 총 비용: price + 2*price + 3*price
  // ...
  // n번 탔을 때 총 비용: price + 2*price + 3*price + ... + n* price = (n*(n+1)/2) *price

  //매니저님 말씀해주신 내용 :1+2+3+...+n =n*(n+1)/2

  let totalprice = price * ((count * (count + 1)) / 2); //totalprice: n번 탔을 때 총 비용
  return Math.max(totalprice - money, 0);
  //return totalprice >= money ? totalprice - money : 0; //totalprice가 money보다 클 때는 차액을, 아니면 0을 리턴
}
