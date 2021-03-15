# :four_leaf_clover: 알고리즘에 필요한 기본 개념

---
## :watch: 시간 복잡도
- 시간복잡도란 임의의 코드가 문제를 해결하기위한 수행시간이 어느정도 인지를 대략적으로 정량화 한 것이다.
- 입력된 자료의 양과 알고리즘 실행에 걸리는 시간과는 깊은 연관이 있다.
- 시간 복잡도를 나타낼 때에는 Big O 표기법을 이용한다. 

예를 들어서, 1부터 n까지의 합을 구한다고 할 때, 다음과 같은 두 가지 방법이 있다.


    // 방법 1 처음부터 끝까지 더하기
    int n, ans = 0;
    for (int i = 1; i <= n;, i++) {
        ans += i;
    }
    cout << ans << endl;

    // 방법 2 수학적 원리를 사용
    int n, ans = 0;
    ans = n*(n+1)/2;
    cout << ans << endl;


#### 방법1 에서는 for반복문을 이용해 n번의 연산을 하기 때문에 O(n) 의 시간 복잡도를 가진다.<br>
#### 하지만 방법2 에서는 n의 크기와 상관 없이 1번의 연산(n*(n+1)/2)을 하기 때문에 O(1) 의 시간 복잡도를 가진다.

---

## 시간 복잡도 설명
> - O(1) – 상수 시간 : n의 값에 관계없이 한번의 계산으로 해결된다.
> - O(log n) – 로그 시간 : 문제를 해결하기위한 연산횟수가 log 형태이다.
> - O(n) – 선형 시간 : 문제를 해결하기 위해 N 번 연산이 수행된다. 
> - O(n log n) - 선형 로그시간 : 문제를 해결하기 위해 N*(logN) 번 연산이 수행된다. 
> - O(n^2) – 다차 시간 : 문제를 해결하기 위해 입력값 n의 제곱번 연산이 수행된다.
> - O(2^n) – 지수 시간 : 문제를 해결하기 위해 상수값 2(설명을 위한 임의의 값) 의 n 제곱번 연산이 수행된다.
> - O(n!) - 팩토리얼 시간 : 13! 만 되어도 62억을 넘어가며 int의 범위를 훌쩍 넘어선다 

#### 컴퓨터는 2진수를 사용하므로 log 는 상용로그가 아니라 log_2이다. 편의를 위해 log로만 칭한다.<br>
#### 위로 갈수록 수행시간이 빠르고, 아래로 갈 수록 수행시간이 느려진다.<br>
#### 코드의 시간복잡도값이 1억 정도라면 일반적인 문제풀이 시간기준인 1초 이내에 풀 수 있다.<br>

- [조금 더 자세한 설명](https://velog.io/@bathingape/Time-Complexity%EC%8B%9C%EA%B0%84%EB%B3%B5%EC%9E%A1%EB%8F%84)
- [시간복잡도 wiki](https://ko.wikipedia.org/wiki/%EC%8B%9C%EA%B0%84_%EB%B3%B5%EC%9E%A1%EB%8F%84)

---
<br>

## :key: 알고리즘 이론을 공부하는데 참고하기 좋은 사이트 ☆
 > - [BaaaaaaaarkingDog_Blog](https://blog.encrypted.gg/category/%EA%B0%95%EC%A2%8C/%EC%8B%A4%EC%A0%84%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)<br>
 > - [동빈나_Blog](https://m.blog.naver.com/ndb796/221233570962)<br>
 > - [Ries 마법의 슈퍼마리오_Blog](https://m.blog.naver.com/kks227/220769859177)<br>
 > - [GeeksforGeeks](https://www.geeksforgeeks.org/searching-algorithms/)는 영어로 되어있지만 페이지 번역을 통해 봐도 무방합니다. 알고리즘에 대한 설명이 정말 잘 되어있으며 알고리즘에 대한 예시코드들도 다양한 언어(c, c++, java, python)로 짜여있습니다<br>
> - [VisuAlgo](https://visualgo.net/en) 알고리즘의 동작 방식을 애니매이션으로 시각화 해놓은 사이트 입니다. 그림으로 이해하는데 큰 도움이 될 수 있습니다.<br>
> - [USF](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html) 위와 마찬가지로 공부하고자 하는 알고리즘이 목록에 있다면 이론보다 먼저 동작 방식을 보는게 훨씬 효율적일 수 있습니다.<br>
> - [동적계획법의 개념부터 고급 문제풀이까지](https://web.archive.org/web/20150427205243/https://www.acmicpc.net/wiki/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%EB%8F%99%EC%A0%81_%EA%B3%84%ED%9A%8D%EB%B2%95_-_dynamic_programming#folded_1)
---
