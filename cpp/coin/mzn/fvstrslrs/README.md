# Five-Star Sellers

Third-party companies that sell their products on acme.org are able to analyze the customer reviews for their products in real time. Imagine that Acme is creating a category called "five-star-sellers" that will only display products sold by companies whose avarage percentage of five-star reviews per-product is at or above a certain threshold. Given the number of five-star and total reviews for each product a company sells, as well as the threshold percentage, what is the minimum number of additional five-star reviews the company needs to become a five-star seller?

For example, let's say there are 3 products (n = 3) where productRatings =[[4, 4], [1, 2], [3, 6]], and the percentage ratingsThreshold = 77. The first number for each product in productRatings denotes the number of five-star reviews, and the second denotes the number of total reviews. Here is how we can get the seller to reach the threshold with the minimum number of additional five-star reviews:

* Before we add more five-star reviews, the percentage for this seller is ((4/4)+(1/2)+(3/6))/3 = 66.66%

* If we add a five-star review to the second product, the percentage raises to ((4/4)+(2/3)+(3/6))/3 = 72.22%

* If we add another five-star review to the second product, the percentage raises to ((4/4)+(3/4)+(3/6))/3 = 75.00%

* If we add a five-star review to the third product, the percentage rises to ((4/4)+(3/4)+(4/7))/3 = 77.38%

At this point the the threshold of 77% has been met. Therefore, the answer is 3 because that is the minimum number of additional five-star reviews the company needs to become a five-star seller.
