// antlr3customtokenstream.h — Custom ANTLR3 token stream with selectively switchable channels.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef	_ANTLR3_CUSTOMTOKENSTREAM_H
#define	_ANTLR3_CUSTOMTOKENSTREAM_H


#include <antlr3tokenstream.h>

#define ANTLR3_TOKEN_SWITCHABLE_CHANNEL	ANTLR3_TOKEN_DEFAULT_CHANNEL + 1

#ifdef __cplusplus
extern "C" {
#endif

/** Custom token stream is an implementation of ANTLR_TOKEN_STREAM for the default
 *  parsers and recognizers. This implementation is able to selectively listen on
 *	a special token channel at runtime.
 */
typedef	struct	ANTLR3_CUSTOM_TOKEN_STREAM_struct
{
    /** The ANTLR3_TOKEN_STREAM interface implementation, which also includes
     *  the intstream implementation. We could duplicate the pANTLR_INT_STREAM
     *  in this interface and initialize it to a copy, but this could be confusing
     *  it just results in one more level of indirection and I think that with
     *  judicial use of 'const' later, the optimizer will do decent job.
     */
    pANTLR3_TOKEN_STREAM    tstream;

    /** Whatever is supplying the CUSTOM_TOKEN_STREAM needs a pointer to itself
     *  so that this can be accessed by any of the API functions which it implements.
     */
    void		    * super;

    /** Records every single token pulled from the source indexed by the token index.
     *  There might be more efficient ways to do this, such as referencing directly in to
     *  the token factory pools, but for now this is convenient and the ANTLR3_LIST is not
     *  a huge overhead as it only stores pointers anyway, but allows for iterations and 
     *  so on.
     */
    pANTLR3_VECTOR	    tokens;

    /** Override map of tokens. If a token type has an entry in here, then
     *  the pointer in the table points to an int, being the override channel number
     *  that should always be used for this token type.
     */
    pANTLR3_LIST	    channelOverrides;

    /** Discared set. If a token has an entry in this table, then it is thrown
     *  away (data pointer is always NULL).
     */
    pANTLR3_LIST	    discardSet;

    /* The channel number that this token stream is tuned to. For instance, whitespace
     * is usually tuned to channel 99, which no token stream would normally tune to and
     * so it is thrown away.
     */
    ANTLR3_UINT32	    channel;

    /** If this flag is set to ANTLR3_TRUE, then tokens that the stream sees that are not
     *  in the channel that this stream is tuned to, are not tracked in the
     *  tokens table. When set to false, ALL tokens are added to the tracking.
     */
    ANTLR3_BOOLEAN	    discardOffChannel;

    /** The index into the tokens list of the current token (the next one that will be
     *  consumed. p = -1 indicates that the token list is empty.
     */
    ANTLR3_INT32	    p;

    /** A simple filter mechanism whereby you can tell this token stream
     *  to force all tokens of type ttype to be on channel.  For example,
     *  when interpreting, we cannot exec actions so we need to tell
     *  the stream to force all WS and NEWLINE to be a different, ignored
     *  channel.
     */
    void		    (*setTokenTypeChannel)  (struct ANTLR3_CUSTOM_TOKEN_STREAM_struct * tokenStream, 
							ANTLR3_UINT32 ttype, ANTLR3_UINT32 channel);

    /** Add a particular token type to the discard set. If a token is found to belong 
     *  to this set, then it is skipped/thrown away
     */
    void		    (*discardTokenType)	    (struct ANTLR3_CUSTOM_TOKEN_STREAM_struct * tokenStream, ANTLR3_INT32 ttype);

    /** Signal to discard off channel tokens from here on in.
     */
    void		    (*discardOffChannelToks)(struct ANTLR3_CUSTOM_TOKEN_STREAM_struct * tokenStream, ANTLR3_BOOLEAN discard);

    /** Function that returns a pointer to the ANTLR3_LIST of all tokens
     *  in the stream (this causes the buffer to fill if we have not get any yet)
     */
    pANTLR3_VECTOR	    (*getTokens)	    (struct ANTLR3_CUSTOM_TOKEN_STREAM_struct * tokenStream);

    /** Function that returns all the tokens between a start and a stop index.
     *  TODO: This is a new list (Ack! Maybe this is a reason to have factories for LISTS and HASHTABLES etc :-( come back to this)
     */
    pANTLR3_LIST	    (*getTokenRange)	    (struct ANTLR3_CUSTOM_TOKEN_STREAM_struct * tokenStream, ANTLR3_UINT32 start, ANTLR3_UINT32 stop);

    /** Function that returns all the tokens indicated by the specified bitset, within a range of tokens
     */
    pANTLR3_LIST	    (*getTokensSet)	    (struct ANTLR3_CUSTOM_TOKEN_STREAM_struct * tokenStream, 
							ANTLR3_UINT32 start, ANTLR3_UINT32 stop, pANTLR3_BITSET types);
    
    /** Function that returns all the tokens indicated by being a member of the supplied List
     */
    pANTLR3_LIST	    (*getTokensList)	    (struct ANTLR3_CUSTOM_TOKEN_STREAM_struct * tokenStream, 
							ANTLR3_UINT32 start, ANTLR3_UINT32 stop, pANTLR3_LIST list);

    /** Function that returns all tokens of a certain type within a range.
     */
    pANTLR3_LIST	    (*getTokensType)	    (struct ANTLR3_CUSTOM_TOKEN_STREAM_struct * tokenStream, 
							ANTLR3_UINT32 start, ANTLR3_UINT32 stop, ANTLR3_UINT32 type);

    /** Function that resets the token stream so that it can be reused, but
     *  but that does not free up any resources, such as the token factory
     *  the factory pool and so on. This prevents the need to keep freeing
     *  and reallocating the token pools if the thing you are building is
     *  a multi-shot dameon or somethign like that. It is much faster to
     *  just reuse all the vectors.
     */
    void                    (*reset)            (struct ANTLR3_CUSTOM_TOKEN_STREAM_struct * tokenStream);

    /** Function that knows how to free an ANTLR3_CUSTOM_TOKEN_STREAM
     */
    void		    (*free)		    (struct ANTLR3_CUSTOM_TOKEN_STREAM_struct * tokenStream);

	/** Extra data for custom token stream (can't be accessed by parser generated code) **/
	ANTLR3_BOOLEAN					swChannelState;

}
    ANTLR3_CUSTOM_TOKEN_STREAM;

typedef ANTLR3_CUSTOM_TOKEN_STREAM *pANTLR3_CUSTOM_TOKEN_STREAM;

ANTLR3_API pANTLR3_CUSTOM_TOKEN_STREAM
antlr3CustomTokenDebugStreamSourceNew(ANTLR3_UINT32 hint, pANTLR3_TOKEN_SOURCE source, pANTLR3_DEBUG_EVENT_LISTENER debugger);

ANTLR3_API pANTLR3_CUSTOM_TOKEN_STREAM
antlr3CustomTokenStreamSourceNew(ANTLR3_UINT32 hint, pANTLR3_TOKEN_SOURCE source);

ANTLR3_API pANTLR3_CUSTOM_TOKEN_STREAM
antlr3CustomTokenStreamNew(ANTLR3_UINT32 hint);

// TODO: Add functions here to turn on/off the switchable channel & the boolean var

#ifdef __cplusplus
	}
#endif

#endif
