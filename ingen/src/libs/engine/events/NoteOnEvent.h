/* This file is part of Ingen.  Copyright (C) 2006 Dave Robillard.
 * 
 * Ingen is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 * 
 * Ingen is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef NOTEONEVENT_H
#define NOTEONEVENT_H

#include "Event.h"
#include "types.h"
#include <string>
using std::string;

namespace Om {

class Node;


/** A note on event.
 *
 * \ingroup engine
 */
class NoteOnEvent : public Event
{
public:
	NoteOnEvent(CountedPtr<Responder> responder, samplecount timestamp, Node* patch, uchar note_num, uchar velocity);
	NoteOnEvent(CountedPtr<Responder> responder, samplecount timestamp, const string& node_path, uchar note_num, uchar velocity);
	
	void execute(samplecount offset);
	void post_process();

private:
	Node*  m_node;
	string m_node_path;
	uchar  m_note_num;
	uchar  m_velocity;
	bool   m_is_osc_triggered;
};


} // namespace Om

#endif // NOTEONEVENT_H
