class ErrorFinder
{
	public:
		ErrorFinder();
		int GetErrorsCount();
		const char* mainRegexp;
		static constexpr char* noteStart = "(Each undeclared identifier is reported only once";
		static constexpr char* noteEnd = "for each function it appears in.)";
};