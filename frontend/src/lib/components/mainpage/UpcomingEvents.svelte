<script lang="ts">
    import { onMount } from 'svelte'
    import axios from 'axios'
    import { env } from '$env/dynamic/public'
    import ContactUsBackground from '$lib/assets/contactus/ContactUsBackground.webp'

    const API_BASE = env.PUBLIC_API_BASE_URL

    interface UpcomingEvent {
        title: string
        description: string
        location: string
        start: string
        end: string
        all_day: boolean
        recurrence: string | null
    }

    interface UpcomingEventsResponse {
        events: UpcomingEvent[]
        subscribe: {
            google: string
            ics: string
        }
    }

    let events = $state<UpcomingEvent[]>([])
    let googleCalendarUrl = $state('')
    let icsCalendarUrl = $state('')
    let isLoading = $state(true)
    let failed = $state(false)

    function formatWhen(event: UpcomingEvent): string {
        const start = new Date(event.start)
        if (Number.isNaN(start.getTime())) return ''

        if (event.all_day) {
            return start.toLocaleDateString('en-AU', {
                weekday: 'short',
                day: 'numeric',
                month: 'short',
                timeZone: 'Australia/Sydney'
            })
        }

        const datePart = start.toLocaleDateString('en-AU', {
            weekday: 'short',
            day: 'numeric',
            month: 'short',
            timeZone: 'Australia/Sydney'
        })
        const timePart = start.toLocaleTimeString('en-AU', {
            hour: 'numeric',
            minute: '2-digit',
            timeZone: 'Australia/Sydney'
        })
        return `${datePart} · ${timePart}`
    }

    async function fetchEvents() {
        if (!API_BASE) {
            failed = true
            isLoading = false
            return
        }

        try {
            const response = await axios.get<UpcomingEventsResponse>(`${API_BASE}/api/events/upcoming/`)
            const data = response.data
            events = Array.isArray(data?.events) ? data.events : []
            googleCalendarUrl = data?.subscribe?.google ?? ''
            icsCalendarUrl = data?.subscribe?.ics ?? ''
        } catch {
            failed = true
            events = []
            googleCalendarUrl = ''
            icsCalendarUrl = ''
        } finally {
            isLoading = false
        }
    }

    onMount(() => {
        fetchEvents()
    })
</script>

<section id="upcoming-events" class="relative w-full scroll-mt-32 overflow-hidden bg-black text-white">
    <img
        src={ContactUsBackground}
        alt=""
        class="pointer-events-none absolute inset-0 z-0 h-full w-full select-none object-cover"
    />

    <svg class="pointer-events-none absolute inset-0 z-[1] h-full w-full opacity-10 mix-blend-overlay" aria-hidden="true">
        <defs>
            <pattern id="upcoming-grid" width="72" height="72" patternUnits="userSpaceOnUse">
                <path d="M 72 0 L 0 0 0 72" fill="none" stroke="white" stroke-width="4" />
            </pattern>
        </defs>
        <rect width="100%" height="100%" fill="url(#upcoming-grid)" />
    </svg>

    <div class="relative z-10 mx-auto flex w-full max-w-5xl flex-col gap-10 px-8 py-20 md:px-12 md:py-24">
        <div class="flex flex-col gap-4 md:flex-row md:items-end md:justify-between">
            <div class="max-w-xl">
                <h2 class="text-5xl font-bold tracking-tight md:text-6xl lg:text-7xl">Upcoming Events</h2>
                <!-- <p class="mt-4 font-mono text-xs leading-relaxed text-white/75 md:text-[14px]">
                    CPMSoc's upcoming workshops, events and activities. 
                </p> -->
            </div>

            <div class="flex shrink-0 flex-wrap gap-3">
                {#if googleCalendarUrl}
                    <a
                        href={googleCalendarUrl}
                        target="_blank"
                        rel="noreferrer noopener"
                        class="bg-white px-4 py-2 font-mono text-sm text-black transition-colors hover:bg-[#eeeeee]"
                    >
                        Add to Google Calendar
                    </a>
                {/if}
                {#if icsCalendarUrl}
                    <a
                        href={icsCalendarUrl}
                        target="_blank"
                        rel="noreferrer noopener"
                        class="border border-white/40 px-4 py-2 font-mono text-sm text-white transition-colors hover:bg-white/10"
                    >
                        Add to other calendar (ICS)
                    </a>
                {/if}
            </div>
        </div>

        {#if isLoading}
            <p class="font-mono text-sm text-white/60">Loading events…</p>
        {:else if failed}
            <p class="font-mono text-sm text-white/60">
                Events are unavailable right now. Subscribe to the calendar above to stay in the loop.
            </p>
        {:else if events.length === 0}
            <p class="font-mono text-sm text-white/60">No upcoming events listed yet — check back soon.</p>
        {:else}
            <ul class="flex flex-col divide-y divide-white/15 border-y border-white/15">
                {#each events as event (event.start + event.title)}
                    <li class="flex flex-col gap-2 py-6 md:flex-row md:gap-10">
                        <time
                            datetime={event.start}
                            class="shrink-0 font-mono text-xs tracking-wide text-[#c4b5e0] md:w-44 md:text-sm"
                        >
                            {formatWhen(event)}
                        </time>
                        <div class="min-w-0 flex-1">
                            <div class="flex flex-wrap items-baseline gap-x-3 gap-y-1">
                                <h3 class="text-xl font-semibold tracking-tight md:text-2xl">{event.title}</h3>
                                {#if event.recurrence}
                                    <span class="font-mono text-xs uppercase tracking-wider text-[#c4b5e0]">
                                        {event.recurrence}
                                    </span>
                                {/if}
                            </div>
                            {#if event.location}
                                <p class="mt-1 font-mono text-xs text-white/65 md:text-sm">{event.location}</p>
                            {/if}
                            {#if event.description}
                                <p class="mt-2 font-mono text-xs leading-relaxed text-white/55 md:text-[13px]">
                                    {event.description.length > 180
                                        ? `${event.description.slice(0, 180).trimEnd()}…`
                                        : event.description}
                                </p>
                            {/if}
                        </div>
                    </li>
                {/each}
            </ul>
        {/if}
    </div>
</section>
