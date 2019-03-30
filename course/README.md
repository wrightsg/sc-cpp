# Day 2

* Book: GOOS (Growing Object-Oriented Software, Guided by Tests)
* "London school" TDD -> write (failing) acceptance test first, then start unit testing the entry point of the system (typically service class that will delegate to other classes)
* Design entry point: make list of things that need to be done, decide where this functionality needs to live (i.e. same class or separate class(es))
* Test entry point by mocking classes to which functionality was delegated, once functionality of entry point was implemented and verified move "inward"; run acceptance test after implementing each class
* Testing pyramid: the broader the unit under test the less tests; unit under test has to be defined by designer (e.g. entire system, single class, flow, etc)
* Test level have no global naming convention; acceptance test / unit test / component test / integration test

* Book: "Working effectively with legacy code" (Michael Feathers)

# Day 3

* Book: Domain Driven Design (boring but good :)); blue (older) and red (newer) book, Sandro recommends going for blue book first (more theoretical)
* App structure (code organization defines the architecture!)
  * Split core and delivery mechanism
  * Split core into
    * infrastructure
    * model: contains nouns (what is the system about? e.g. "book", "user")
      * contains entities, aggregates, repositories, domain services, value objects,...?
    * actions: contains verbs (what does the system do? e.g. "AddBookToWishList", "SearchBooks" etc.)
  * As core grows, create subcategories for related stuff
    * model: group related domain concepts (e.g. "products" super category for "book" and "electronics")
    * actions: group epic/theme (e.g. "purchase" for "AddBookToWishList", "MakePayment", "ValidateCreditCard")
    => bounded context