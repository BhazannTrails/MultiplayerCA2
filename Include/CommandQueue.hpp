#ifndef Include_COMMANDQUEUE_HPP
#define Include_COMMANDQUEUE_HPP

#include <Include/Command.hpp>

#include <queue>


class CommandQueue
{
	public:
		void						push(const Command& command);
		Command						pop();
		bool						isEmpty() const;

		
	private:
		std::queue<Command>			mQueue;
};

#endif // Include_COMMANDQUEUE_HPP
